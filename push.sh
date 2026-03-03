#!/bin/bash

set -e

echo "==== 변경사항 stash ===="
git stash -u

echo "==== git pull (rebase) ===="
git pull --rebase origin master

echo "==== stash 복원 ===="
git stash pop || true

echo "==== .exe 파일 삭제 시작 ===="
find . -type f -name "*.exe" -exec rm -f {} \;

echo "==== git add ===="
git add .

COMMIT_DATE=$(date "+%Y-%m-%d")
COMMIT_MSG="${COMMIT_DATE}"

echo "==== git commit ===="
if git diff --cached --quiet; then
    echo "변경 사항이 없어 커밋하지 않습니다."
else
    git commit -m "${COMMIT_MSG}"
fi

echo "==== git push ===="
git push origin master

echo "==== 완료 ===="