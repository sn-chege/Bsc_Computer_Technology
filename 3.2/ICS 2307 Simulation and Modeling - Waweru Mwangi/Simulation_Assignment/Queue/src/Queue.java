import java.util.Scanner;

public class Queue{
    private static final int Q_LIMIT = 100;
    private static final int BUSY = 1;
    private static final int IDLE = 0;
    private static int next_event_type,num_custs_delayed,num_delays_required,num_events,num_in_q,server_status;
    private static double area_num_in_q,area_server_status,mean_interarrival,mean_service,time,time_last_event,total_of_delays;
    private static double[] time_arrival = new double[Q_LIMIT+1];
    private static double[] time_next_event = new double[3];

    //initialization

    public static void initialize(){
        time  = 0.0;
        server_status= IDLE;
        num_in_q = 0;
        time_last_event = 0.0;
        num_custs_delayed = 0;
        total_of_delays = 0.0;
        area_num_in_q = 0.0;
        area_server_status = 0.0;
        time_next_event[1] = time + expon(mean_interarrival);
        time_next_event[2] = Math.pow(10.0,30.0);

    }

    public static double expon(double mean){
        double u;
        u = Math.random();
        return -mean* Math.log(u);

    }
    // timing method
    public static void timing(){
        double min_time_next_event = Math.pow(10.0,29.0);
        next_event_type = 0;

        for (int i=1; i<=num_events; i++){
            if (time_next_event[i] < min_time_next_event){
                min_time_next_event = time_next_event[i];
                next_event_type = i;
            }
        }

        if (next_event_type == 0){
            System.out.println("Event list empty at time "+time);
        }

        time = min_time_next_event;
    }
    //arrive method
    public static void arrive(){
        double delay;
        time_next_event[1] = time + expon(mean_interarrival);
        if (server_status == BUSY){
            ++num_in_q;
            if (num_in_q>Q_LIMIT){
                System.out.println("Overflow of the array time_arrival at time" +time);
            }
            time_arrival[num_in_q] = time;
        }
        else {
            delay = 0.0;
            total_of_delays += delay;

            ++num_custs_delayed;
            server_status = BUSY;

            time_next_event[2] = time + expon(mean_service);
        }
    }
    //depart
    public static void depart(){
        double delay;

        if (num_in_q == 0){
            server_status = IDLE;
            time_next_event[2] = Math.pow(10.0,30.0);
        }
        else {
            --num_in_q;

            delay = time - time_arrival[1];
            total_of_delays += delay;

            ++num_custs_delayed;
            time_next_event[2] = time + expon(mean_service);

            for (int i=1; i<=num_in_q; i++){
                time_arrival[i] = time_arrival[i+1];
            }
        }
    }
    //report method
    public static void report(){
        System.out.printf("Average delay in queue: %.3f\n",total_of_delays/num_custs_delayed);
        System.out.printf("Average number in queue: %.3f\n",area_num_in_q/time);
        System.out.printf("Server utilization: %.3f\n",area_server_status/time);
        System.out.printf("Time simulation ended: %.3f\n",time);
    }
    // update area_server_status
    public static void update_time_avg_stats(){
        double time_since_last_event;

        time_since_last_event = time - time_last_event;
        time_last_event = time;

        area_num_in_q += num_in_q * time_since_last_event;

        area_server_status += server_status * time_since_last_event;
    }

    //main
    public static void main(String[] args){
        num_events = 2;

        mean_interarrival = 1.0;
        mean_service = 0.5;
        num_delays_required = 1000;

        System.out.println("Single server queueing system with fixed run");
        System.out.println();
        System.out.println("Mean inter-arrival time:  "+mean_interarrival);
        System.out.println("Mean service time:  "+mean_service);
        System.out.println("Number of customers:  "+num_delays_required);
        System.out.println();

        initialize();

        while (num_custs_delayed < num_delays_required){
            timing();

            update_time_avg_stats();

            switch (next_event_type){
                case 1:
                    arrive();
                    break;
                case 2:
                    depart();
                    break;
            }
        }

        report();
    }
}