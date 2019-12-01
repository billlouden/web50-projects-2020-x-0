import csv
import email
import imaplib

# ==================================================================
# Bill Louden, CS50 student   bill@billlouden.com
# Prototype program to open a gmail account, retrieve UNSEEN emails,
# and process those that match a specific subject.
# Within emails of that subject, select six specific tuples of data,
# and process them into a string to be appended both to a local text
# file as well as appended to a CSV file.
#
# This is not the most efficient way to do this, but I wanted to learn
# how to access emails through python and write/append the processed
# data to the files.
# ==================================================================
# NOTE:  I WAS UNABLE TO GET THIS TO WORK THROUGH THE CS50 WEBSITE
# USING FLASK.  SO, THIS WAS COMPILED TO RUN ON MY PC USING THE
# PYCHARM IDE.
# ==================================================================
# THE HARDCODED VARIABLES BELOW WILL EXPIRE 12/31/19
# ==================================================================

usr = "williamlouden@gmail.com"
pwd = "wcjwjznrkjlwzcvq"
subj = "FW: Stats update from FreeFaucet.io"
frm = "bill@billlouden.com"
# ==================================================================
# Eventually write to prompt for a get_input of some sort
# usr, pwd, frm, subj will eventually be an html form, not hard-coded
# ==================================================================

mail = imaplib.IMAP4_SSL('imap.gmail.com')
(retcode, capabilities) = mail.login(usr, pwd)
mail.list()
mail.select('inbox')
n = 0
(retcode, messages) = mail.search(None, 'FROM', frm)
if retcode == 'OK':

    for num in messages[0].split() :
        # ==================================================================
        # Iterate through messages; Let the operator know I am doing something
        # ==================================================================
        print ('Processing')

        typ, data = mail.fetch(num, '(RFC822)')

        for response_part in data:
            # need to parse out the information I want
             if isinstance(response_part, tuple):
                 # ==================================================================
                 # from the IMAPLIB, Return a message object structure from a bytes-like object.
                 # ==================================================================
                original = email.message_from_bytes(response_part[1])
                raw_email = data[0][1]
                message = raw_email.decode('windows-1252')
                # print(message) # for testing
                if isinstance(response_part, tuple):

                    for part in original.get_payload():
                        if (part.get_content_type() == "text/plain"):  # ignore attachments/html
                            body = part.get_payload(decode=True)
                            save_string = str(r"mail.txt")

                            out = (body.decode('windows-1252'))
                            # ==================================================================
                            # The body is an unstructured multiline string so we have to split it;
                            # once split, we need to parse each list element to remove the ": "
                            # and replace with comma.
                            # ==================================================================
                            out = (out.splitlines())
                            if (original['Subject']) == subj:
                                # ==================================================================
                                # First I want to open a text file and append the data.
                                # This raw text file is not necessary for the CSV but it provides
                                # a backup in case something goes wrong with the CSV.
                                # ==================================================================
                                myfile = open(save_string, 'a')
                                # print(original['From'])  # just for testing
                                # print(original['Subject'] + "\n") # for testing
                                # ==================================================================
                                # The date includes the day of week, Tue, 26 Nov 2019 15:29:41 +0000
                                # which I don't want, so I will throw it away and use the [2] partition
                                # ==================================================================
                                date = (original['Date'].rpartition(', ')[2])
                                # ==================================================================
                                # the date is also in a UTC format with time zone, etc.
                                # which now looks like this: 26 Nov 2019 15:29:41 +0000
                                # I only want the first 11 chars (DD MMM YYYY), then add comma delimiter
                                # ==================================================================
                                myfile.write("," + date[:11] + ",")
                                csv_rows = ("," + date[:11] + ",")
                                # ==================================================================
                                # From the large un-formatted email, I only want to grab six elements.
                                # So, I will iterate through the out file for the below tuples
                                # ==================================================================
                                for x in range(len(out)):
                                        # print(out,"\n") # test

                                        if ("Total user accounts" in out[x] or "New users yesterday" in out[x])\
                                                or "New users this week" in out[x] or "Active users this week" in out[x]\
                                                or "Total claims ever" in out[x] or "Total claims 24h" in out[x]:
                                            n = n + 1
                                            label = out[x].partition(':')[0]
                                            result = out[x].rpartition(':')[2]

                                            # ==================================================================
                                            # format of CSV file is 8 columns, 1st one blank
                                            # ||    |Total   |New Users|New users|Active users|Total | Claims |
                                            # ||Date|user    | past 24 |this week| this week  |Claims| past   |
                                            # ||    |accounts|  hours  |         |            |      |24 hours|
                                            # ==================================================================
                                            # I know the label, so I don't have to write it to a file
                                            # ==================================================================
                                            column_label = out[x].partition(':')[0] # not used
                                            row_result = out[x].rpartition(':')[2]
                                            # ==================================================================
                                            # I can write each data element to the text file, but I have to
                                            # build a string before I write the entire row to the CSV.
                                            # ==================================================================
                                            myfile.write(row_result +",")
                                            csv_rows += row_result+","
                                # ==================================================================
                                # when done with this row write end of line to text file
                                # ==================================================================
                                myfile.write("\n")

                                # ==================================================================
                                # Open CSV file for appending, for Windows,we don't want extra line
                                # so we use newline=''
                                # We also do not want double quotation marks around string,
                                # so we use QUOTE_NONE
                                # ==================================================================
                                fields = [csv_rows]
                                with open(r'ffstats.csv', 'a', newline='') as f:
                                    writer = csv.writer(f, delimiter='\t', quoting=csv.QUOTE_NONE, quotechar='')
                                    # ==================================================================
                                    # Now we can write the entire row and return for next search
                                    # ==================================================================
                                    writer.writerow(fields)


print(n, "emails processed")
print('=====done=====' + '\n')

mail.close()

