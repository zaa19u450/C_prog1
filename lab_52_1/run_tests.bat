@echo off
cls
app.exe in_1.txt > out.txt
fc out.txt out_1.txt
app.exe st > out.txt
fc out.txt out_2.txt
app.exe ft in_3.txt > out.txt
fc out.txt out_3.txt
app.exe db > out.txt
fc out.txt out_4.txt
app.exe gt th > out.txt
fc out.txt out_5.txt
app.exe st unknown.txt > out.txt
fc out.txt out_6.txt
app.exe ft in_7.txt > out.txt
fc out.txt out_7.txt
app.exe st in_8.txt > out.txt
fc out.txt out_8.txt
app.exe ft in_9.txt file_out.txt t > out.txt
fc out.txt out_9.txt
app.exe st in_10.txt > out.txt
fc out.txt out_10.txt
app.exe st in_11.txt > out.txt
fc out.txt out_11.txt
app.exe st in_12.txt > out.txt
fc out.txt out_12.txt
app.exe sb in_13.bin > out.txt
fc out.txt out_13.txt
app.exe ft in_14.txt out.txt Za
fc out.txt out_14.txt
app.exe fb in_14.bin out.bin Za
fc out.bin out_14.bin
app.exe dt in_15.txt
fc in_15.txt out_15.txt
app.exe db in_15.bin
fc in_15.bin out_15.bin
pause

