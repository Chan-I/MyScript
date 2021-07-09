set source_dir=D:\forbid
set target_dir=I:\Documents

robocopy %source_dir% %target_dir% /s /MIR /R:3 /W:60 /LOG:%target_dir%\copyLog.txt /xf *.bat *.lnk *.ini
pause