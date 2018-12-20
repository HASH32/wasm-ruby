module WikiExample
  class WikiManager
    attr_accessor :active
    def connect
      self.active = _we_connected
    end

    def get_version
      return 2
    end

    # _we_connected() is defined in C
  end
end
