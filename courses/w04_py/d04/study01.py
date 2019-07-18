import os
import time
import datetime

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
stock_code = '035420'
TEMPLATES_DIR = os.path.join(BASE_DIR, "templates")

# Date Time Format
timestr = None
FORMAT_DATE = "%Y%m%d"
FORMAT_DATETIME = "%Y%m%d%H%M%S"

def get_time_str():
    global timestr
    timestr = datetime.datetime.fromtimestamp(
        int(time.time())).strftime(FORMAT_DATETIME)
    return timestr

log_dir = os.path.join(BASE_DIR, 'logs/%s' % stock_code)
timestr = get_time_str()

print(timestr)



# if not os.path.exists('logs/%s' % stock_code):
#     os.makedirs('logs/%s' % stock_code)
# file_handler = logging.FileHandler(filename=os.path.join(
#     log_dir, "%s_%s.log" % (stock_code, timestr)), encoding='utf-8')
# stream_handler = logging.StreamHandler()
# file_handler.setLevel(logging.DEBUG)
# stream_handler.setLevel(logging.INFO)
# logging.basicConfig(format="%(message)s",
#                     handlers=[file_handler, stream_handler], level=logging.DEBUG)


