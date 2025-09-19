-- CAR_RENTAL_COMPANY_CAR: 대여중인 자동차 정보
-- CAR_RENTAL_COMPANY_RENTAL_HISTORY: 자동차 대여 기록 정보
-- CAR_RENTAL_COMPANY_DISCOUNT_PLAN: 자동차 종류 별 대여 기간 종류 별 할인 정책 정보
-- 7일 이상, 30일 이상, 90일 이상

-- CAR_RENTAL_COMPANY_CAR 테이블과 CAR_RENTAL_COMPANY_RENTAL_HISTORY 테이블과 CAR_RENTAL_COMPANY_DISCOUNT_PLAN 테이블에서 
-- 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중 
-- 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고 
-- 30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차에 대해서 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트를 출력하는 SQL문을 작성해주세요. 

-- 결과는 대여 금액을 기준으로 내림차순 정렬하고, 대여 금액이 같은 경우 자동차 종류를 기준으로 오름차순 정렬, 자동차 종류까지 같은 경우 자동차 ID를 기준으로 내림차순 정렬해주세요.

-- 대여 금액 -> 

select 
    car.car_id, 
    car.car_type,
    round(((car.daily_fee * 30) * (1-(plan.DISCOUNT_RATE / 100)))) as fee
from CAR_RENTAL_COMPANY_CAR car
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN plan
    on car.car_type = plan.car_type
where (car.CAR_TYPE = '세단' or car.CAR_TYPE ='SUV') 
    and plan.DURATION_TYPE = '30일 이상'
    and ((car.daily_fee * 30) * (1-(plan.DISCOUNT_RATE / 100))) >= 500000 
    and ((car.daily_fee * 30) * (1-(plan.DISCOUNT_RATE / 100))) < 2000000
    and car.car_id not in (
        select history.car_id
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY history
        where (history.start_date <= '2022-11-30') and (history.end_date >= '2022-11-01'))
order by fee desc, car.car_type, car_id desc;

