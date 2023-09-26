import openai
from lib.utils import OsUtil as util
import time
openai.api_key =  'sk-' 
 # 'sk-' || common 'sk-'

CODE_RULE_PATH = "mydata/output_rules.txt"
WRONG_FORMAT_PATH = "mydata/wrong_format.txt"
CUSTOMER_REQ_PATH = "mydata/customer_requirements.txt"
REPLY_PATH = "mydata/relayData.txt"
MESSAGE_PATH = "mydata/message.txt"
SOURCE_PATH = "D:/11.Algorithm/01.Learning/04.CodeByAi/myApplication/"
RELEASE_PATH = "D:/11.Algorithm/01.Learning/04.CodeByAi/Release"
RELEASE_OUTPUT_PATH = "D:/11.Algorithm/01.Learning/04.CodeByAi/Release/output.txt"
MAKE32_PATH =  "D:/02.SoftwareImplement/QT/Tools/mingw530_32/bin/mingw32-make"
PRO_PATH = "D:/11.Algorithm/01.Learning/04.CodeByAi/myApplication/myApplication.pro"
EXE_PATH = "/release/myApplication.exe"
OUTPUT_ERROR_PATH = "mydata/build_result.txt"
IS_REQUEST_AGAIN = True
messages = [{"role": "system", "content":
			"You are a intelligent assistant."}]
chat = openai.ChatCompletion.create(
	model="gpt-3.5-turbo", messages=messages,
	temperature=0.1
)
COUNT_REQUEST = 0

def _start_chat(reqID):
	global messages, chat
	
	if(reqID == 1):
		message = util.get_text_from_file(CODE_RULE_PATH) + util.get_text_from_file(CUSTOMER_REQ_PATH) + util.get_text_from_file(WRONG_FORMAT_PATH)
	elif (reqID == 2):
		util.warn("Check the error of extract code")
		#time.sleep(10)
		message = util.get_text_from_file(WRONG_FORMAT_PATH)
	elif (reqID == 3):
		util.error("Check the error of build step")
		time.sleep(100)
		message = util.get_text_from_file(OUTPUT_ERROR_PATH) + util.get_text_from_file(WRONG_FORMAT_PATH)
	elif(reqID == 4):
		message = "Please check the main.qml file, some code line was wrong"
	messages.clear()
	if message:
		messages.append(
			{"role": "user", "content": message},
		)
		util.write_to_file(MESSAGE_PATH, message)
		chat = openai.ChatCompletion.create(
			model="gpt-3.5-turbo",
			messages=messages
		)
	reply = chat.choices[0].message.content
	messages.append({"role": "assistant", "content": reply})
	return reply

def fullStep(reqID):
	global COUNT_REQUEST
	COUNT_REQUEST += 1
	if(COUNT_REQUEST > 60):
		util.error("TOO MANY REQUEST!")
		return
	util.info(f'++++++++++++++ {COUNT_REQUEST} ++++++++++++++ ')
	reply_data = _start_chat(reqID)
	util.write_to_file(REPLY_PATH,reply_data)
	reply_data = util.get_text_from_file(REPLY_PATH)
	data_map = util.extract_data(reply_data)
	if(len(data_map) > 0):
		for key, value in data_map.items(): util.write_to_file(SOURCE_PATH + key, value)
		util.build_release(PRO_PATH,RELEASE_PATH,MAKE32_PATH)
		# check the file, success or not. 
		data_build = util.check_output_file(RELEASE_OUTPUT_PATH)
		if(len(data_build) == 0):
			util.write_to_file(OUTPUT_ERROR_PATH, "Successful!!!")
			util.run_release_exe(RELEASE_PATH + EXE_PATH)
			#code not corect. rebuild
			fullStep(4)
		else:
			data_build_temp = ""
			for match in data_build:
				data_build_temp += match + "\n"
			util.write_to_file(OUTPUT_ERROR_PATH, data_build_temp)
			fullStep(3)
	else:
		util.error("Cannot get the code, WRONG FORMAT") 
		fullStep(2)

if __name__ == '__main__':
	util.clear_console()
	
	util.info(" ---------------- START OF CODE ----------------")
	fullStep(1)
	# util.run_release_exe(RELEASE_PATH + EXE_PATH)
	util.info(" ---------------- END OF CODE ----------------")