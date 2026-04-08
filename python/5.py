#练习         验证一组医疗数据


#导入re库 后使用fullmatch函数
import re

#导入病人列表字典
medical_records = [
    {
        'patient_id': 'P1001',
        'age': 34,
        'gender': 'Female',
        'diagnosis': 'Hypertension',
        'medications': ['Lisinopril'],
        'last_visit_id': 'V2301',
    },
    {
        'patient_id': 'p1002',
        'age': 47,
        'gender': 'male',
        'diagnosis': 'Type 2 Diabetes',
        'medications': ['Metformin', 'Insulin'],
        'last_visit_id': 'v2302',
    },
    {
        'patient_id': 'P1003',
        'age': 29,
        'gender': 'female',
        'diagnosis': 'Asthma',
        'medications': ['Albuterol'],
        'last_visit_id': 'v2303',
    },
    {
        'patient_id': 'p1004',
        'age': 56,
        'gender': 'Male',
        'diagnosis': 'Chronic Back Pain',
        'medications': ['Ibuprofen', 'Physical Therapy'],
        'last_visit_id': 'V2304',
    }
]

#查找病人是否合规
def find_invalid_records(
    patient_id, age, gender, diagnosis, medications, last_visit_id
):
    #创建判断字典 判断每一个key的值是否符合要求
    constraints = {
        'patient_id': isinstance(patient_id, str) and re.fullmatch('p\d+', patient_id, re.IGNORECASE),
        'age': isinstance(age, int) and age >= 18,
        'gender': isinstance(gender, str) and gender.lower() in ('male', 'female'),
        'diagnosis': isinstance(diagnosis, str) or diagnosis is None,
        'medications': isinstance(medications, list) and all([isinstance(i, str) for i in medications]),
        'last_visit_id': isinstance(last_visit_id, str) and re.fullmatch('v\d+', last_visit_id, re.IGNORECASE)
    }

    return [key for key, value in constraints.items() if not value]

#判断病人函数
def validate(data):
    #判断传入的是否为列表或元组
    is_sequence = isinstance(data, (list, tuple))

    #如果都不是返回错误
    if not is_sequence:
        print('Invalid format: expected a list or tuple.')
        return False
        
    #创建变量用于判断数据是否合规
    is_invalid = False
    #创建key集合 后用于判断
    key_set = set(
        ['patient_id', 'age', 'gender', 'diagnosis', 'medications', 'last_visit_id']
    )

    #判断数据函数
    for index, dictionary in enumerate(data):

        #判断传入是否为字典类型
        if not isinstance(dictionary, dict):
            print(f'Invalid format: expected a dictionary at position {index}.')
            is_invalid = True
            continue

        #判断key是否正确
        if set(dictionary.keys()) != key_set:
            print(
                f'Invalid format: {dictionary} at position {index} has missing and/or invalid keys.'
            )
            is_invalid = True
            continue

        #调用find_invalid_records函数判断key的值是否正确
        invalid_records = find_invalid_records(**dictionary)
        for key in invalid_records:
            val = dictionary[key]
            print(f"Unexpected format '{key}: {val}' at position {index}.")
            is_invalid = True

    #所传入的数据是否合规
    #不合规返回
    if is_invalid:
        return False
    #合格返回
    print('Valid format.')
    return True

validate(medical_records)