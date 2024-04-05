# [중앙값 ](https://www.codetree.ai/missions/13/problems/median)

|유형|문제 경험치|난이도|
|---|---|---|
|[Samsung / 시간 최적화 / Priority Queue](https://www.codetree.ai/missions?missionId=13)|70xp|![어려움][hard]|








[b5]: https://img.shields.io/badge/Bronze_5-%235D3E31.svg
[b4]: https://img.shields.io/badge/Bronze_4-%235D3E31.svg
[b3]: https://img.shields.io/badge/Bronze_3-%235D3E31.svg
[b2]: https://img.shields.io/badge/Bronze_2-%235D3E31.svg
[b1]: https://img.shields.io/badge/Bronze_1-%235D3E31.svg
[s5]: https://img.shields.io/badge/Silver_5-%23394960.svg
[s4]: https://img.shields.io/badge/Silver_4-%23394960.svg
[s3]: https://img.shields.io/badge/Silver_3-%23394960.svg
[s2]: https://img.shields.io/badge/Silver_2-%23394960.svg
[s1]: https://img.shields.io/badge/Silver_1-%23394960.svg
[g5]: https://img.shields.io/badge/Gold_5-%23FFC433.svg
[g4]: https://img.shields.io/badge/Gold_4-%23FFC433.svg
[g3]: https://img.shields.io/badge/Gold_3-%23FFC433.svg
[g2]: https://img.shields.io/badge/Gold_2-%23FFC433.svg
[g1]: https://img.shields.io/badge/Gold_1-%23FFC433.svg
[p5]: https://img.shields.io/badge/Platinum_5-%2376DDD8.svg
[p4]: https://img.shields.io/badge/Platinum_4-%2376DDD8.svg
[p3]: https://img.shields.io/badge/Platinum_3-%2376DDD8.svg
[p2]: https://img.shields.io/badge/Platinum_2-%2376DDD8.svg
[p1]: https://img.shields.io/badge/Platinum_1-%2376DDD8.svg
[passed]: https://img.shields.io/badge/Passed-%23009D27.svg
[failed]: https://img.shields.io/badge/Failed-%23D24D57.svg
[easy]: https://img.shields.io/badge/쉬움-%235cb85c.svg?for-the-badge
[medium]: https://img.shields.io/badge/보통-%23FFC433.svg?for-the-badge
[hard]: https://img.shields.io/badge/어려움-%23D24D57.svg?for-the-badge


-------------------------------
Priority_Queue를 푸는 문제
------------------------------
1. pq를 2개 사용해서 값을 업데이트 하는 것이 어려웠다. high면 high -> low로 하나씩 구현해야한다.
2. pq size값을 비교하기 위해서는 int 캐스팅이 중요하다.
3. 답지에서는 midean값을 선언하고, 이 값을 업데이트한다. lower PQ와 higer PQ의 top 값을 뽑아서 기존 midean 값을 설정한 뒤 이를 정렬한다.
4. int nums[] = {median, arr[i], new_cand}; 와 같은 스킬도 사용하기 편할 것 같다.
5. 여러개의 테스트 케이스에서는 함수보다 나이브한 작성법이 더욱 편리하다. pq를 새로 선언하지 못해 비워주는 함수를 만들어야 했다.
