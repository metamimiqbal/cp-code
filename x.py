import json

with open('quran-database/data/quran.json', 'r', encoding='utf-8') as f:
    data = json.load(f)

first_verse = data[0] # The data is an array of verses
print(f"{first_verse['surah_name']} ({first_verse['surah_number']}:{first_verse['ayah_number']})")
print(first_verse['text'])
print(first_verse['translation'])