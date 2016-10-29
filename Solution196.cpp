
//题目196，Delete Duplicate Emails 删除重复邮箱

//SQL语句删除掉给定数据库表中的重复邮箱记录
//1、
DELETE FROM Person WHERE Id NOT IN
(SELECT Id FROM (SELECT MIN(Id) Id FROM Person GROUP BY Email) p);

//2、
DELETE p2 FROM Person p1 JOIN Person p2
ON p2.Email = p1.Email WHERE p2.Id > p1.Id

//3、
DELETE p2 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p2.Id > p1.Id;
