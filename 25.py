def verify_card_number(card_number):
    cleaned = card_number.replace('-', '').replace(' ', '')

    digits = [int(c) for c in cleaned]

    total = 0

    for i in range(len(digits) - 2, -1, -2):
        doubled = digits[i] * 2

        if doubled > 9:
            doubled -= 9
        total += doubled

    for i in range(len(digits) - 1, -1, -2):
        total += digits[i]

    if total % 10 == 0:
        return 'VALID'
    else:
        return 'INVALID'