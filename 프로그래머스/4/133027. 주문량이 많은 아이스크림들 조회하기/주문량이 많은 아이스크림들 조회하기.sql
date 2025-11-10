select j.flavor
from first_half f join (
    select flavor, sum(total_order) as jul_order
    from july
    group by flavor
) as j on f.flavor = j.flavor
order by f.TOTAL_ORDER + j.jul_order desc
limit 3;