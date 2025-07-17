# select month(cc.start_date), cc.CAR_ID, sum(cc.records) as RECORDS
# from (
#     select car_id, month(start_date), count(*)
#     from (
#         select * 
#         from CAR_RENTAL_COMPANY_RENTAL_HISTORY c 
#         where month(c.start_date) >= '8' 
#             and month(c.start_date) <= '10'
#     ) as n
#     group by n.car_id
#     having count(*) >= 5
# ) as cc
# group by month(cc.start_date) 
# order by month(cc.start_date) asc, cc.car_id desc;

# select month(start_date) as MONTH, CAR_ID, count(*) as RECORDS
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where car_id, month(start_date)
# having count(*) >= 5
# order by m asc, car_id desc;

SELECT 
    MONTH(H.START_DATE) AS MONTH,
    H.CAR_ID,
    COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H
WHERE H.CAR_ID IN (
    SELECT CAR_ID
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
    GROUP BY CAR_ID
    HAVING COUNT(*) >= 5
)
AND H.START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
GROUP BY MONTH(H.START_DATE), H.CAR_ID
ORDER BY MONTH ASC, H.CAR_ID DESC;