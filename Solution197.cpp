
//题目197，Rising Temperature 上升温度

//给定Weather表，写SQL找出比前一天温度高的Id
//1、
SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND DATEDIFF(w1.Date, w2.Date) = 1;

//2、
SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND TO_DAYS(w1.Date) = TO_DAYS(w2.Date) + 1;

//3、
SELECT w1.Id FROM Weather w1, Weather w2
WHERE w1.Temperature > w2.Temperature AND SUBDATE(w1.Date, 1) = w2.Date;

//4、
SELECT Id FROM (
SELECT CASE WHEN Temperature > @pre_t AND DATEDIFF(Date, @pre_d) = 1 THEN Id ELSE NULL END AS Id,
@pre_t := Temperature, @pre_d := Date
FROM Weather, (SELECT @pre_t := NULL, @pre_d := NULL) AS init ORDER BY Date ASC
) id WHERE Id IS NOT NULL;
