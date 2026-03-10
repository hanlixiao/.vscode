test_settings = {'theme': 'dark', 'notifications': 'enabled', 'volume': 'high'}

def add_setting(dictionary, tupel):
    key = tupel[0].lower()
    value = tupel[1].lower()
    if key in dictionary:
        return f"Setting '{key}' already exists! Cannot add a new setting with this name."
    dictionary[key] = value
    return f"Setting '{key}' does not exist! Cannot update a non-existing setting."

def update_setting(dictionary, tupel):
    key = tupel[0].lower()
    value = tupel[1].lower()
    if not key in dictionary:
        return f"Setting '{key}' does not exist! Cannot update a non-existing setting."
    dictionary[key] = value
    return f"Setting '{key}' updated to '{value}' successfully!"

def delete_setting(dictionary, key):
    key = key.lower()
    if not key in dictionary:
        return f"Setting not found!"
    del dictionary[key]
    return f"Setting '{key}' deleted successfully!"

def view_settings(dictionary):
    if dictionary == {}:
        return 'No settings available.'
    return f"Current User Settings:\nTheme: {dictionary['theme']}\nNotifications: {dictionary['notifications']}\nVolume: {dictionary['volume']}\n"
