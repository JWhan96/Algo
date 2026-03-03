#!/bin/bash

# 에러 발생 시 즉시 종료
set -e

echo "==== .exe 파일 삭제 시작 ===="
find . -type f -name "*.exe" -exec rm -f {} \;

echo "==== git add ===="
git add .

# 현재 날짜/시간 기반 커밋 메시지 생성
COMMIT_DATE=$(date "+%Y-%m-%d %H:%M:%S")
COMMIT_MSG="auto commit: ${COMMIT_DATE}"

echo "==== git commit ===="
git commit -m "${COMMIT_MSG}" || echo "변경 사항이 없어 커밋하지 않습니다."

echo "==== git push ===="
git push origin master

echo "==== 완료 ===="