set source_dir=D:\forbid
set target_dir=%~dp0

robocopy %source_dir% %target_dir% *.* /E /COPY:DAT /MT:8 /s /R:3 /W:60  /xf *.bat *.lnk *.ini *.ezy  #/LOG:%target_dir%\copyLog.txt
pause
