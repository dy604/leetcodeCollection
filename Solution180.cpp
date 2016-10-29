
//题目180，Consecutive Numbers 连续的数字

//给定Logs表，查询Num列中连续出现相同数字三次的数字
//1、
SELECT DISTINCT l1.Num FROM Logs l1
JOIN Logs l2 ON l1.Id = l2.Id - 1
JOIN Logs l3 ON l1.Id = l3.Id - 2
WHERE l1.Num = l2.Num AND l2.Num = l3.Num;

//2、
SELECT DISTINCT l1.Num FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id = l2.Id - 1 AND l2.Id = l3.Id - 1
ANd l1.Num = l2.Num AND l2.Num = l3.Num;

//3、
SELECT DISTINCT Num FROM (
SELECT Num, @count := IF(@pre = Num, @count + 1, 1) AS n, @pre := Num
FROM Logs, (SELECT @count := 0, @pre := -1) AS init
) AS t WHERE t.n >= 3；
