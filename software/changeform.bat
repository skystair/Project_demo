
@echo off
setlocal enabledelayedexpansion

:: 设置源扩展名列表
set "extensions=.uvprojx .lst"

echo 开始处理当前目录及子目录下的文件...
echo 目标：将 .uvprojx 和 .lst 文件复制为 .o 文件
echo ----------------------------------------

:: 遍历定义的扩展名
for %%e in (%extensions%) do (
    echo 正在处理扩展名: %%e
    
    :: 递归查找当前目录(.)下所有匹配扩展名的文件
    for /r "." %%f in (*%%e) do (
        if exist "%%f" (
            :: 获取文件路径和名称
            set "source_file=%%f"
            
            :: 构建目标文件名：保留原路径和主文件名，更改扩展名为 .o
            :: %%~dpf 表示驱动器和路径
            :: %%~nf 表示文件名（不含扩展名）
            set "target_file=%%~dpnf.o"
            
            :: 执行复制操作，保持内容不变
            copy /y "%%f" "!target_file!" > nul
            
            if !errorlevel! equ 0 (
                echo [成功] "%%f" -> "!target_file!"
            ) else (
                echo [失败] "%%f"
            )
        )
    )
)

echo ----------------------------------------
echo 处理完成。
pause
