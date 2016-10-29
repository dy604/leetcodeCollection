
//题目194，Transpose File 转置文件

//编写脚本完成文件内容类似矩阵转置的操作
//1、
awk '{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) s[i] = $i;
        else s[i] = s[i] " " $i;
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' file.txt

//2、
while read -a line; do
    for ((i = 0; i < "${#line[@]}"; ++i)); do
        a[$i]="${a[$i]} ${line[$i]}"
    done
done < file.txt
for ((i = 0; i < ${#a[@]}; ++i)); do
    echo ${a[i]}
done
