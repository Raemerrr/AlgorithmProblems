
class Solution {
  public String solution(String[] participant, String[] completion) {
    String answer = "";
    java.util.HashMap<String, Integer> m = new java.util.HashMap<>();
    for (String el : participant) {
      if (m.containsKey(el)) {
        m.put(el, m.get(el) + 1);
      } else {
        m.put(el, 1);
      }
    }
    for (String el : completion) {
      if (m.containsKey(el)) {
        Integer val = m.get(el);
        // 동명이인의 경우를 처리하기 위해
        if (val > 1) {
          m.put(el, val - 1);
        } else {
          m.remove(el);
        }
      } else {
        answer = el;
        // 해당 처리를 하지 않아도 정답 처리는 된다.
        // 하지만 본인은 아래의 "완주하지 못한 사람에 대한 처리"로직이 있어 m을 비워준다.
        m.clear();
        break;
      }
    }
    // 완주하지 못한 사람에 대한 처리
    for (String key : m.keySet()) {
      answer = key;
    }
    return answer;
  }
}

// BOJ 제출 시 class 이름을 Main으로 변경 할 것
public class PGM_완주하지못한선수_210404 {
  public static void main(String[] args) {
    Solution s = new Solution();
    String[] participant = { "mislav", "stanko", "mislav", "ana" };
    String[] completion = { "stanko", "ana", "mislav" };
    System.out.println(s.solution(participant, completion));
  }
}