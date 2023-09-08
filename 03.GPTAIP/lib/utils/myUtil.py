def write_to_file(filepath, data):
    try:
        file = open(filepath, 'w')
        file.write(data)
        file.close()
        print("Ghi dữ liệu thành công vào tệp tin", filepath)
    except IOError:
        print("Không thể ghi dữ liệu vào tệp tin", filepath)
