@echo off
setlocal

REM Kiểm tra đối số đầu vào
if "%~1"=="" (
    echo Usage: bra filename
    exit /b 1
)

REM Lấy tên file không có phần mở rộng
set "filename=%~n1"
set "ext=%~x1"

REM Kiểm tra xem phần mở rộng có phải là .cpp không
if /I not "%ext%"==".cpp" (
    echo Error: Only .cpp files are supported.
    exit /b 1
)

REM Biên dịch bằng g++, thêm cờ -DONLINE_JUDGE
g++ -DONLINE_JUDGE "%~1" -o "%filename%.exe"
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

REM Chạy chương trình
echo Running %filename%.exe with ONLINE_JUDGE ...
"%filename%.exe"

endlocal
