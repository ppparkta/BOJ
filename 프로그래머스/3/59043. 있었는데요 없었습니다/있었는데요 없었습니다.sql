select ai.ANIMAL_ID, ai.name
from ANIMAL_OUTS ao
join ANIMAL_INS ai on ao.animal_id = ai.animal_id
where ai.datetime > ao.datetime
order by ai.datetime asc;