# import hashlib
# inputstring=input("Enetr the string:")
# output=hashlib.md5(inputstring.encode())
# print("THE output stirng is :")
# print(output.hexdigest())
# //

import hashlib
ip=input("Enter the string:")
op=hashlib.md5(ip.encode())
print(op.hexdigest())









