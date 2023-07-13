/* Write an SQL query to find all dates' Id with
   higher temperatures compared to its previous
   dates (yesterday). */

SELECT w1.id
FROM weather_info w1
JOIN weather_info w2
ON w1.record_date = DATE_ADD(w2.record_date, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature;
