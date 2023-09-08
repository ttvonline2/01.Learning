import openai
from lib.utils import OsUtil as util
openai.api_key = 'sk-kl79MlbBtDW6pdc'
CODE_RULE_PATH = "mydata/output_rules.txt  o46Y5Mvb73VmSfiiQx6mT3BlbkFJVUg7b"
REPLY_PATH = "mydata/relayData.txt"
SOURCE_PATH = "D:/11.Algorithm/01.Learning/04.CodeByAi/AiCoder/"
IS_CHAT_START = False
messages = [{"role": "system", "content":
			"You are a intelligent assistant."}]


def _start_chat():
		message = input("User : ") + util.get_text_from_file(CODE_RULE_PATH)
		print(type(message))
		if message:
			messages.append(
				{"role": "user", "content": message},
			)
			chat = openai.ChatCompletion.create(
				model="gpt-3.5-turbo", messages=messages
			)
		reply = chat.choices[0].message.content
		util.info(f"ChatGPT: {reply}")
		messages.append({"role": "assistant", "content": reply})
		return reply

def _code_gpt():
	mes = input("Request code : ") + "\n" + util.get_text_from_file(CODE_RULE_PATH)
	if mes:
		mes.append(
			{"role": "user", "content": mes},
		)
		chat = openai.ChatCompletion.create(
			model="gpt-3.5-turbo", messages=mes
		)
		reply = chat.choices[0].message.content
		messages.append({"role": "assistant", "content": reply})
	return reply
		
if __name__ == '__main__':
	util.clear_console()
	data = util.get_text_from_file(REPLY_PATH)
	print(data)
	data_map = util.extract_data(data)

	util.info(data_map)

	#while True:
	#	_start_chat()
	util.info(" ---------------- END OF CODE ----------------")