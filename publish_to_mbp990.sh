#!/bin/sh
rsync -avz --exclude-from=exclude-publish.rsync --no-o --no-p --no-g UDSOnlineEditor/ rsync://jwsu@mbp990/work/OnlineEditor/OnlineEditor/UDSOnlineEditor/ 
