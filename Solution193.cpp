
//题目193，Valid Phone Numbers 验证电话号码

//利用脚本验证给定txt文件中的电话号码
//1、
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt

//2、
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt

//3、
1 grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
