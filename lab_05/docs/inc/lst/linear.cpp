#include <queue>
#include <mutex>
#include <cstdio>
#include <cstdlib>

static void fprint_array(FILE *f, const int *const array, const int size)
{
	for (int i = 0; i < size; i++)
		fprintf(f, "%d ", array[i]);
	fprintf(f, "\n");
}

void log_data(const request_t *const request)
{
	fprintf(request->f, "Substring: %s\n", request->substring);
	fprintf(request->f, "Default: %d comparisons; occurences: ", request->noc_1);
	fprint_array(request->f, request->occurrences_1, request->noo_1);
	fprintf(request->f, "KMP    : %d comparisons; occurences: ", request->noc_2);
	fprint_array(request->f, request->occurrences_2, request->noo_2);
	fprintf(request->f, "\n");
}

static void stage_1(std::queue<request_t> &q1, std::queue<request_t> &q2)
{
    std::mutex m;
    m.lock();
    request_t request = q1.front();
    m.unlock();
	request.noc_1 = search_default(request.substring, request.text, request.occurrences_1, &request.noo_1);
    m.lock();
    q2.push(request);
    m.unlock();
    m.lock();
    q1.pop();
    m.unlock();
}

static void stage_2(std::queue<request_t> &q2, std::queue<request_t> &q3)
{
    std::mutex m;
    m.lock();
    request_t request = q2.front();
    m.unlock();
    request.noc_2 = search_kmp(request.substring, request.text, request.occurrences_2, &request.noo_2);
    m.lock();
    q3.push(request);
    m.unlock();
    m.lock();
    q2.pop();
    m.unlock();
}

static void stage_3(std::queue<request_t> &q3, int task_num)
{
    std::mutex m;
    m.lock();
    request_t request = q3.front();
    m.unlock();
    log_data(&request);
    m.lock();
    q3.pop();
    m.unlock();
}

void linear_processing(int num_of_requests, char *text, char substrings[][50])
{
	size_t time_start = 0, time_end = 0;
	FILE *f = fopen("linear.log", "w");
    std::queue<request_t> q1, q2, q3;
    std::mutex m;
    for (int i = 0; i < num_of_requests; i++)
    {
        request_t request = generate_request(f, text, substrings[i]);
        q1.push(request);
    }
    get_time(time_start);
    for (int i = 0; i < num_of_requests; i++)
    {
        stage_1(std::ref(q1), std::ref(q2));
        stage_2(std::ref(q2), std::ref(q3));
        stage_3(std::ref(q3), i + 1);
    }
	get_time(time_end);
	printf("Time: %zu ticks.\n", time_end - time_start);
	fclose(f);
}
