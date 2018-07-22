using System;
using System.Threading;

namespace SnakeCS
{
    class KeyInput
    { 
        private Thread thread;

        public bool Listen { get; private set; } = false;

        private Handler handler;

        public KeyInput(Handler handler)
        {
            this.handler = handler;

            Start();
        }

        public void Start()
        {
            Listen = true;
            thread = new Thread(Run);
            thread.Start();
        }

        public void Run()
        {
            while (Listen)
            {
                System.ConsoleKeyInfo key = Console.ReadKey();
                handler.input(key);
            }
        }

        public void Stop()
        {
            thread.Join();
        }
    }
}
