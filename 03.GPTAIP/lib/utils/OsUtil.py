import os
import zipfile
import shutil
import re

CWD = os.getcwd()

class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

#
# console helpers
#
def _set_console_color(color):
    print(color, end='')

def _reset_console_color():
    print(Colors.ENDC, end='')

def clear_console():
    os.system('cls' if os.name=='nt' else 'clear')

def _print_prompt_title(title, new_line=False):
    _set_console_color(Colors.OKBLUE + Colors.BOLD)
    print('[?] {}: '.format(title), end = None if new_line else '')
    _reset_console_color()

def _print_prompt_item(item, header='', is_default=False):
    _set_console_color(Colors.BOLD)
    print('      {}{} {}'.format('*' if is_default else ' ',
        header,
        ' - ' if header != '' else ''),
            end='')
    _reset_console_color()
    _set_console_color(Colors.OKCYAN)
    print(item)
    _reset_console_color()

def _print_prompt_user_option(default_index=None):
    _set_console_color(Colors.BOLD + Colors.OKBLUE)
    if default_index is not None:
        print('     Your option ({}): '.format(default_index), end='')
    else:
        print('     Your option: ', end='')
    _reset_console_color()

def debug(msg):
    print('       {}'.format(msg))
    _reset_console_color()

def info(msg):
    _set_console_color(Colors.OKGREEN)
    print('INFO:  {}'.format(msg))
    _reset_console_color()

def warn(msg):
    _set_console_color(Colors.WARNING)
    print('WARN:  {}'.format(msg))
    _reset_console_color()

def error(msg):
    _set_console_color(Colors.FAIL)
    print('ERROR: {}'.format(msg))
    _reset_console_color()

#
# console prompt helpers
#
def prompt_yn(msg, default='y'):
    while True:
        _print_prompt_title('{} ({})'.format(msg, '*y/n' if default=='y' else 'y/*n'))
        user_input = input().lower()

        if user_input == 'y':
            return True
        if user_input == 'n':
            return False
        if user_input == '':
            return default == 'y'
        
        error('Invalid input')

def prompt_str(msg):
    _print_prompt_title(msg)
    return input()

def prompt_select_list(title, the_list, allow_other_option=True):
    _print_prompt_title(title, new_line=True)

    default_option = 1 if len(the_list) > 0 else None
    
    index = 1
    for item in the_list:
        _print_prompt_item(item, header=index, is_default=default_option == index)
        index += 1
    
    if allow_other_option:
        _print_prompt_item('Select another', header=0)

    while True:
        _print_prompt_user_option(default_option)
        user_input = input()
        if user_input == '':
            selection = 1 # default select the first item
        else:
            selection = int(user_input) 

        if allow_other_option and selection == 0:
            return prompt_str('Input your option')
        
        selection -= 1
        
        if selection < 0 or selection >= len(the_list):
            error('Invalid option')
        else:
            break

    return the_list[selection]
#
# local file helpers
#
def list_files(path='.'):
    path = os.path.abspath(path)
    prev_cwd = os.getcwd()

    os.chdir(path)
    entries = os.listdir(path)
    result = [f for f in entries if os.path.isfile(f)]
    os.chdir(prev_cwd)

    return result

def list_folders(path='.'):
    path = os.path.abspath(path)
    prev_cwd = os.getcwd()

    os.chdir(path)
    entries = os.listdir(path)
    result = [f for f in entries if os.path.isdir(f)]
    os.chdir(prev_cwd)

    return result

def remove_entry(path):
    if len(path) == 0:
        return

    if not os.path.exists(path):
        return

    info(f'Removing "{path}"')

    if os.path.isfile(path):
        os.remove(path)
    else:
        # os.rmdir(path)
        shutil.rmtree(path, ignore_errors=True)

def copy(src, dest):
    shutil.copytree(src, dest, ignore=shutil.ignore_patterns('.git', '.moc', '.obj', '.qrc', '.vscode', '.qtc_clangd', '.ccls*')) # reduce copy time and storage

def has_entry(name, path='.'):
    # folders = list_folders(path)
    # files = list_files(path)
    # return (name in folders or name in files)
    prev_cwd = os.getcwd()
    os.chdir(path)
    result = os.path.exists(name)
    os.chdir(prev_cwd)
    return result

def rename(old, new):
    os.rename(old, new)

def make_dir(name):
    os.makedirs(name, exist_ok=True)

def is_file(path):
    return os.path.isfile(path)

def unzip(filename, dest='.'):
    info(f'Extracting "{filename}"...')
    with zipfile.ZipFile(filename, 'r') as zip_ref:
        zip_ref.extractall(dest) 

def zip(inpath, outfile):
    info(f'Compressing "{inpath}"...')
    outfile = outfile.replace('.zip', '')
    # with zipfile.ZipFile(filename, 'w', zipfile.ZIP_DEFLATED) as zip_ref:
    #     zip_ref.write(filename)
    shutil.make_archive(outfile, 'zip', inpath)

def get_text_from_file(file_path):
    try:
        with open(file_path, 'r') as file:
            text = file.read()
        return text
    except FileNotFoundError:
        warn("File not found.")
        return None

def write_to_file(filepath, data):
    try:
        file = open(filepath, 'w')
        file.write(data)
        file.close()
        print("Write success", filepath)
    except IOError as e:
        print("Can't write to ", filepath)
        print("Error:", str(e))


def split_data(data):
    pattern = r'\d+\.\s+(\w+\.h|main\.cpp):\s+([\s\S]+?)(?=\n\d+\.|$)'
    matches = re.findall(pattern, data)

    result = {}
    for i, match in enumerate(matches):
        key = f"key {i+1}"
        value = match[1].strip()
        result[key]= value

    return result