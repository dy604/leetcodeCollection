
//题目182，Duplicate Emails 重复的邮箱

//给定Person表，写查询重复的邮箱
//1、
SELECT Email FROM Person GROUP BY Email
HAVING COUNT(*) > 1;

//2、
SELECT DISTINCT p1.Email FROM Person p1
JOIN Person p2 ON p1.Email = p2.Email
WHERE p1.Id <> p2.Id
