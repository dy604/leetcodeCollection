
//题目178，Rank Scores 分数排行

//将给定的Scores表排名次，相同的分数名次一样，名次不能空缺
//1、
SELECT Score,
(SELECT COUNT(DISTINCT Score) FROM Score WHERE Score >= s.Score) Rank
FROM Scores s ORDER BY Score DESC;

//2、
SELECT Score,
(SELECT COUNT(*) FROM (SELECT DISTINCT Score s FROM Scores) t WHERE s >= Score) Rank
FROM Scores ORDER BY Score DESC;

//3、
SELECT s.Score, COUNT(DISTINCT t.Score) Rank
FROM Scores s JOIN Scores t ON s.Score <= t.Score
GROUP BY s.Id ORDER BY s.Score DESC;

//4、这里用了两个变量，变量使用时其前面需要加@，这里的：= 是赋值的意思，
//如果前面有Set关键字，则可以直接用=号来赋值，如果没有，则必须要使用:=来赋值
//<>表示不等于，如果左右两边不相等，则返回true或1，若相等，则返回false或0
SELECT Score,
@rank := @rank + (@pre <> (@pre := Score)) Rank
FROM Scores, (SELECT @rank := 0, @pre := -1) INIT
ORDER BY Score DESC;
