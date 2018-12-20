
require 'webrick'

mime_types = WEBrick::HTTPUtils::DefaultMimeTypes
mime_types.store 'wasm', 'application/wasm'

root = File.expand_path('.')

server = WEBrick::HTTPServer.new(
    Port: 8000,
    DocumentRoot: root,
    MimeTypes: mime_types )

trap('INT') { server.shutdown } # Ctrl-C to stop

server.start
