#练习   加密


#加密函数
def caesar(text, shift, encrypt=True):
    #判断传入shift是否为int
    if not isinstance(shift, int):
        return 'Shift must be an integer value.'
    #判断shift范围是否合规
    if shift < 1 or shift > 25:
        return 'Shift must be an integer between 1 and 25.'
    #字母表
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    #判断是否加密
    if not encrypt:
        shift = - shift
    #加密位移
    shifted_alphabet = alphabet[shift:] + alphabet[:shift]
    #进行对照
    translation_table = str.maketrans(alphabet + alphabet.upper(), shifted_alphabet + shifted_alphabet.upper())
    #返回加密完的语句
    encrypted_text = text.translate(translation_table)

    return encrypted_text

#加密
def encrypt(text, shift):
    return caesar(text, shift)

#解密
def decrypt(text, shift):
    return caesar(text, shift, encrypt=False)

#encrypted_text = caesar('freeCodeCamp', 3)
#print(encrypted_text)

encrypted_text = 'Pbhentr vf sbhaq va hayvxryl cynprf.'
decrypted_text = decrypt(encrypted_text,13)
print(decrypted_text)