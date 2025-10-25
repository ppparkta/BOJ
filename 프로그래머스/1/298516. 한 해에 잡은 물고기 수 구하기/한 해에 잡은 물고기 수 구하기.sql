-- 코드를 작성해주세요

select count(*) as fish_count
from FISH_INFO f 
where substr(f.time, 1, 4) = '2021'; 

# select * from fish_info;
