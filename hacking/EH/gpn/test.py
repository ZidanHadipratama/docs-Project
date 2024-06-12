import os
# Provided encrypted flag and the partial plaintext "GPNCTF{"
enc_flag = bytes.fromhex("d24fe00395d364e12ea4ca4b9f2da4ca6f9a24b2ca729a399efb2cd873b3ca7d9d1fb3a66a9b73a5b43e8f3d")
partial_plaintext = "GPNCTF{".encode()
# Recovering the key using the known part of the plaintext
key = bytearray(5)
for i in range(len(partial_plaintext)):
    key[i % len(key)] = enc_flag[i] ^ partial_plaintext[i]

print(f"Recovered key: {key}")
# Decrypting the entire flag using the recovered key

decrypted_flag = bytearray(len(enc_flag))
for i in range(len(enc_flag)):
    decrypted_flag[i] = enc_flag[i] ^ key[i % len(key)]

print(f"Decrypted flag: {decrypted_flag.decode()}")