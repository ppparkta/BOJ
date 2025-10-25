class Solution {
    
    public static int[] arr;
    public static int answer = 0;
    
    // dfs -> 같은 값에 대해가 아니라 무조건 뎁스 깊어야 함
    public int solution(int[] numbers, int target) {
        arr = numbers;
        calcTarget(0, target, 0);
        return answer;
    }
    
    private void calcTarget(int d, int t, int cur){
        // System.out.println(cur);
        if (d == arr.length) {
            if (cur == t){
                answer++;
            }
            return;
        }
        calcTarget(d+1, t, cur+arr[d]);
        calcTarget(d+1, t, cur-arr[d]);
    }
}