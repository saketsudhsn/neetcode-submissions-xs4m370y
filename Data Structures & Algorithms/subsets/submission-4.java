class Solution {

    private void subsets(int[] nums, int index, List<Integer> list, List<List<Integer>> answer) {

        if (index == nums.length) {
            return;
        }

        for (int idx = index; idx < nums.length; idx++) {
            list.add(nums[idx]);
            answer.add(new ArrayList<>(list));
            subsets(nums, idx + 1, list, answer);
            list.remove(list.size() - 1);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        
        List<List<Integer>> answer = new ArrayList<>();

        answer.add(new ArrayList<>());
        subsets(nums, 0, new ArrayList<>(), answer);
        return answer;
    }
}
