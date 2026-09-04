-- Identify the pattern

-- Ask yourself:
-- Do I need to compare one row with another row of the SAME table?
-- Here, we compare:

-- Today's temperature
--         ↓
-- Previous day's temperature

-- So we need SELF JOIN.

-- 3. Query
-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
-- ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
-- WHERE w1.temperature > w2.temperature;

-- 4. How does the JOIN work?
-- Think of the same table as two copies:
-- w1 = Today's weather
-- w2 = Previous day's weather

-- The condition:
-- DATEDIFF(w1.recordDate, w2.recordDate) = 1

-- means:
-- w1 date = w2 date + 1 day

# Write your MySQL query statement below
select w1.id from weather w1 join weather w2 where datediff(w1.recordDate,w2.recordDate)=1 and w1.temperature>w2.temperature; 