#!/bin/sh
rsync -avz --exclude-from=exclude.rsync --no-o --no-p --no-g rsync://jwsu@mbp990/work/OnlineEditor/OnlineEditor/ .

