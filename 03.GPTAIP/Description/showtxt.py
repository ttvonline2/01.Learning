import os
import time

# Đường dẫn đến thư mục chứa các tệp .txt
directory_path = "/Users/vangtruong/Documents/01.Learning/03.GPTAIP/Description/data"

def clear_screen():
    # Sử dụng mã ANSI escape sequence để xoá màn hình
    os.system('cls' if os.name == 'nt' else 'clear')

def display_txt_info():
    clear_screen()  # Xoá màn hình trước khi hiển thị thông tin

    # Tạo danh sách các tệp .txt trong thư mục
    txt_files = [file for file in os.listdir(directory_path) if file.endswith(".txt")]

    if not txt_files:
        print("Không có tệp .txt nào trong thư mục.")
    else:
        print(f"Number of txt file: {len(txt_files)}")
        for i, txt_file in enumerate(txt_files, start=1):
            file_path = os.path.join(directory_path, txt_file)
            with open(file_path, 'r', encoding='utf-8') as file:
                file_contents = file.read()
            print(f"{i}. {txt_file}")
            print(f"-->{file_contents}\n")

while True:
    display_txt_info()
    time.sleep(1)
