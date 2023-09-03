import openai
openai.api_key = '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'
messages = [ {"role": "system", "content":
			"You are a intelligent assistant."} ]
while True:
	message = input("User : ")
	if message:
		messages.append(
			{"role": "user", "content": message},
		)
		chat = openai.ChatCompletion.create(
			model="gpt-3.5-turbo", messages=messages
		)
	reply = chat.choices[0].message.content
	print(type(reply))
	print(f"ChatGPT: {reply}")
	messages.append({"role": "assistant", "content": reply})
