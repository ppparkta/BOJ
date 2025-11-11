-- 코드를 작성해주세요

select count(*) as fish_count, max(info.new_length) as max_length, info.fish_type
from (
    select f.*,
        case
         when f.length<=10 then 10
         else f.length
        end as new_length
    from FISH_INFO f) as info
group by info.fish_type
having avg(info.new_length) > 33
order by info.fish_type;