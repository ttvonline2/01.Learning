import re

pattern = r'&&&\s*(.*?)\s*&&&'

string = "Hes./;lllo, World!"
pattern = r"\w"
matches = re.findall(pattern, string)
print(matches)
