import hashlib

def hash_password(password):
    # Create a SHA-256 hash object
    sha256 = hashlib.sha256()

    # Update the hash object with the password bytes
    sha256.update(password.encode('utf-8'))

    # Get the hexadecimal representation of the hash
    hashed_password = sha256.hexdigest()

    return hashed_password

# Test the function with the same password as in the C++ code
password = "ali"
hashed_password = hash_password(password)
print(f"Original Password: {password}")
print(f"Hashed Password: {hashed_password}")
# def shift(c, base, offset, mod):
#     return chr((ord(c) - base - offset) % mod + base)

# def shift_string(s, offset):
#     result = ""
#     for c in s:
#         if c.isalpha():
#             base = ord('A') if c.isupper() else ord('a')
#             result += shift(c, base, offset, 26)
#         elif c.isdigit():
#             base = ord('0')
#             result += shift(c, base, offset, 10)
#         else:
#             result += c
#     return result

# s = "KTQMW8TGK_9V_3SF5VJ_GWLW43I5_V9ECYYV9GC"
# shifted_s = shift_string(s, 22)
# print(shifted_s)
