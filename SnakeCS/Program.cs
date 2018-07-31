using System.Threading;
using System;

namespace SnakeCS
{
    class Program
    {
        public bool Running { get; private set; } = false;
        private Handler handler;

        private Thread thread;

        static public int TPS = 30;

        public static int WIDTH = 20, HEIGHT = 10;

        static void Main(string[] args)
        {
            Program Program = new Program();
        }

        public Program()
        {
            handler = new Handler();
            this.Start();
        }

        public void Start()
        {
            Running = true;
            thread = new Thread(Run);
            thread.Start();
        }   

        public void Run()
        {
            
            while (Running)
            {
                Thread.Sleep(1000 / TPS);
                handler.Tick();
            }
        }

        public void Stop()
        {
            thread.Join();
        }
    }
}
