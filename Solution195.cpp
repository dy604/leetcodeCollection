
//题目195，Tenth Line 第十行

//编写脚本打印一个txt文件的第十行
//1、
awk '{if(NR == 10) print $0}' file.txt

//2、
awk 'NR == 10' file.txt

//3、
sed -n 10p file.txt
