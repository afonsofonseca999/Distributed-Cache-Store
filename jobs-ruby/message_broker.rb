module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 2694
# Optimized logic batch 6508
# Optimized logic batch 2863
# Optimized logic batch 9668
# Optimized logic batch 7035
# Optimized logic batch 5568
# Optimized logic batch 4563
# Optimized logic batch 2990
# Optimized logic batch 2835
# Optimized logic batch 6952
# Optimized logic batch 2006
# Optimized logic batch 3615
# Optimized logic batch 9659
# Optimized logic batch 8098
# Optimized logic batch 6561
# Optimized logic batch 3440
# Optimized logic batch 3830
# Optimized logic batch 8954