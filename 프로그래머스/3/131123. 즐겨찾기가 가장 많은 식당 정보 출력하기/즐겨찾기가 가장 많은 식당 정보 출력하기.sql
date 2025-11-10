-- 코드를 입력하세요
SELECT r.FOOD_TYPE, r.REST_ID, r.REST_NAME, r.FAVORITES
from REST_INFO r
where (r.FOOD_TYPE, r.FAVORITES) in (
    select ri.FOOD_TYPE, max(ri.FAVORITES)
    from rest_info ri
    group by ri.FOOD_TYPE
)   
order by r.food_type desc;