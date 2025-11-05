class Solution {
    public static boolean visited[];
    public static int answer;
    public int solution(int[] numbers, int target) {
        visited = new boolean[numbers.length];
        answer = 0;
        dfs(numbers, 0, 0, target);
        return answer;
    }
    
    private void dfs(int[] arr, int depth, int sum, int t) {
        if (depth == arr.length) {
            if (sum == t) {
                answer++;
            }
            return;
        }
        for(int i : new int[]{arr[depth], arr[depth] * -1}) {
            dfs(arr, depth+1, sum+i, t);
        }
    }
}