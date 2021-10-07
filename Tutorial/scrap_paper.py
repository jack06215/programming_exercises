mbyte = 1000
oneHundredMB = b'a'*(1024*1024) * mbyte
f = open("oneGiga", "wb")
f.write(oneHundredMB)
f.close()